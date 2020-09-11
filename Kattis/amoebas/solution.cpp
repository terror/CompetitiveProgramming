#include <bits/stdc++.h>

using namespace std;

const int MXN = 1001;
int n, m, ans = 0;
char adj[MXN][MXN];

// S/SE/E/NE/N/NW/W/SW
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int floodfill(int r, int c, char c1, char c2) {
  if (adj[r][c] != c1) return 0;
  adj[r][c] = c2;
  for (int d = 0; d < 8; ++d) floodfill(r + dr[d], c + dc[d], c1, c2);
  return 1;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> adj[i][j];

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) ans += floodfill(i, j, '#', 'x');

  cout << ans;
}

