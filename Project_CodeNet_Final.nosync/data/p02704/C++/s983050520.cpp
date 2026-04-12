#include <stdio.h>
int n, f, g;
int pc, qc, pa, qa;
int p[500];
int q[500];
int s[500];
int t[500];
unsigned long long x;
int u[500][64];
int v[500][64];
int m[500][500][64];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", s + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", t + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lu", &x);
		for (int j = 0; j < 64; j++) {
			u[i][j] = x % 2;
			x /= 2;
		}
	}
	for (int i = 0; i < n; i++) {
		scanf("%lu", &x);
		for (int j = 0; j < 64; j++) {
			v[i][j] = x % 2;
			x /= 2;
		}
	}
	for (int i = 0; i < 64; i++) {
		pc = 0; qc = 0;
		for (int i = 0; i < n; i++) {
			p[i] = 0; q[i] = 0;
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				m[j][k][i] = 2;
			}
		}
		for (int j = 0; j < n; j++) {
			if (s[j] == 0 && u[j][i] == 1) {
				for (int k = 0; k < n; k++) {
					if (m[j][k][i] == 0)f = 1;
					m[j][k][i] = 1;
				}
				p[j]++; pc++;
			}
			if (s[j] == 1 && u[j][i] == 0) {
				for (int k = 0; k < n; k++) {
					if (m[j][k][i] == 1)f = 1;
					m[j][k][i] = 0;
				}
				p[j]++; pc++;
			}
			if (t[j] == 0 && v[j][i] == 1) {
				for (int k = 0; k < n; k++) {
					if (m[k][j][i] == 0)f = 1;
					m[k][j][i] = 1;
				}
				q[j]++; qc++;
			}
			if (t[j] == 1 && v[j][i] == 0) {
				for (int k = 0; k < n; k++) {
					if (m[k][j][i] == 1)f = 1;
					m[k][j][i] = 0;
				}
				q[j]++; qc++;
			}
		}
		pa = 0; qa = 0;
		if (pc + 1 < n && qc + 1 < n) {
			while (p[pa])pa++;
			while (q[qa])qa++;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (m[j][k][i] == 2) {
						if (j == pa && k == qa)m[j][k][i] = 0;
						if (j == pa && k != qa)m[j][k][i] = 1;
						if (j != pa && k == qa)m[j][k][i] = 1;
						if (j != pa && k != qa)m[j][k][i] = 0;
					}
				}
			}
		}
		if (pc == n - 1) {
			while (p[pa])pa++;
			if (s[pa] == 0) {
				for (int j = 0; j < n; j++) {
					if (t[j] == 0 && v[j][i] == 0) {
						m[pa][j][i] = 0;
					}
					if (t[j] == 1 && v[j][i] == 1) {
						g = 0;
						for (int k = 0; k < n; k++) {
							if (k != pa && m[k][j][i] == 1)g = 1;
						}
						if (g)m[pa][j][i] = 0;
						else m[pa][j][i] = 1;
					}
				}
			}
			if (s[pa] == 1) {
				for (int j = 0; j < n; j++) {
					if (t[j] == 1 && v[j][i] == 1) {
						m[pa][j][i] = 1;
					}
					if (t[j] == 0 && v[j][i] == 0) {
						g = 0;
						for (int k = 0; k < n; k++) {
							if (k != pa && m[k][j][i] == 0)g = 1;
						}
						if (g)m[pa][j][i] = 1;
						else m[pa][j][i] = 0;
					}
				}
			}
		}
		if (qc == n - 1) {
			while (q[qa])qa++;
			if (t[qa] == 0) {
				for (int j = 0; j < n; j++) {
					if (s[j] == 0 && u[j][i] == 0) {
						m[j][qa][i] = 0;
					}
					if (s[j] == 1 && u[j][i] == 1) {
						g = 0;
						for (int k = 0; k < n; k++) {
							if (k != qa && m[j][k][i] == 1)g = 1;
						}
						if (g)m[j][qa][i] = 0;
						else m[j][qa][i] = 1;
					}
				}
			}
			if (t[qa] == 1) {
				for (int j = 0; j < n; j++) {
					if (s[j] == 1 && u[j][i] == 1) {
						m[j][qa][i] = 1;
					}
					if (s[j] == 0 && u[j][i] == 0) {
						g = 0;
						for (int k = 0; k < n; k++) {
							if (k != qa && m[j][k][i] == 0)g = 1;
						}
						if (g)m[j][qa][i] = 1;
						else m[j][qa][i] = 0;
					}
				}
			}
		}
		for (int j = 0; j < n; j++) {
			if (s[j]) {
				g = 0;
				for (int k = 0; k < n; k++) {
					g += m[j][k][i];
				}
				if (g > 0)g = 1;
				if (u[j][i] != g)f = 1;
			}
			else {
				g = 1;
				for (int k = 0; k < n; k++) {
					g *= m[j][k][i];
				}
				if (u[j][i] != g)f = 1;
			}
		}
		for (int j = 0; j < n; j++) {
			if (t[j]) {
				g = 0;
				for (int k = 0; k < n; k++) {
					g += m[k][j][i];
				}
				if (g > 0)g = 1;
				if (v[j][i] != g)f = 1;
			}
			else {
				g = 1;
				for (int k = 0; k < n; k++) {
					g *= m[k][j][i];
				}
				if (v[j][i] != g)f = 1;
			}
		}
	}
	if (f) {
		printf("-1\n");
		return 0;
	}
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			x = 0;
			for (int i = 63; i >= 0; i--) {
				x *= 2;
				x += m[j][k][i];
			}
			printf("%lu", x);
			if (k != n - 1)printf(" ");
		}
		printf("\n");
	}
}