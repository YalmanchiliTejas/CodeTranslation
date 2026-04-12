#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const int Maxn = 505;
const int Maxb = 64;

int n;
int S[Maxn];
int T[Maxn];
ull U[Maxn];
ull V[Maxn];
int row[Maxn], col[Maxn];
int B[Maxn][Maxn];
bool tkrow[Maxn], tkcol[Maxn];
ull res[Maxn][Maxn];

bool assertMarkRow(int r, int val)
{
    for (int i = 0; i < n; i++)
        if (B[r][i] != -1 && B[r][i] != val) return false;
        else B[r][i] = val;
    return true;
}

bool assertMarkCol(int c, int val)
{
    for (int i = 0; i < n; i++)
        if (B[i][c] != -1 && B[i][c] != val) return false;
        else B[i][c] = val;
    return true;
}

void markCol(int c);

void markRow(int r)
{
    tkrow[r] = true;
    for (int i = 0; i < n; i++) if (B[r][i] == -1 && !tkcol[i])
        if (T[i]) { B[r][i] = 1; markCol(i); }
        else { B[r][i] = 0; markCol(i); }
}

void markCol(int c)
{
    tkcol[c] = true;
    for (int i = 0; i < n; i++) if (B[i][c] == -1 && !tkrow[i])
        if (S[i]) { B[i][c] = 1; markRow(i); }
        else { B[i][c] = 0; markRow(i); }
}

bool Solve()
{
    fill((int*)B, (int*)B + Maxn * Maxn, -1);
    fill(tkrow, tkrow + n, false);
    fill(tkcol, tkcol + n, false);
    for (int i = 0; i < n; i++) {
        if (S[i] == 1 && row[i] == 0) {
            if (!assertMarkRow(i, 0)) return false;
            tkrow[i] = true;
        } else if (S[i] == 0 && row[i] == 1) {
            if (!assertMarkRow(i, 1)) return false;
            tkrow[i] = true;
        }
        if (T[i] == 1 && col[i] == 0) {
            if (!assertMarkCol(i, 0)) return false;
            tkcol[i] = true;
        } else if (T[i] == 0 && col[i] == 1) {
            if (!assertMarkCol(i, 1)) return false;
            tkcol[i] = true;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (B[i][j] == 1) {
                if (S[i] == 1 && !tkrow[i]) markRow(i);
                if (T[j] == 1 && !tkcol[j]) markCol(j);
            } else if (B[i][j] == 0) {
                if (S[i] == 0 && !tkrow[i]) markRow(i);
                if (T[j] == 0 && !tkcol[j]) markCol(j);
            } else if (S[i] == 1 && T[i] == 1) {
                B[i][j] = 1;
                if (!tkrow[i]) markRow(i);
                if (!tkcol[j]) markCol(j);
            } else if (S[i] == 0 && T[i] == 0) {
                B[i][j] = 0;
                if (!tkrow[i]) markRow(i);
                if (!tkcol[j]) markCol(j);
            }
    vector <int> myrows, mycols;
    for (int i = 0; i < n; i++) {
        if (!tkrow[i]) myrows.push_back(i);
        if (!tkcol[i]) mycols.push_back(i);
    }
    if (myrows.empty() && mycols.empty()) return true;
    if (myrows.size() <= 1 || mycols.size() <= 1) return false;
    for (int i = 0; i < myrows.size(); i++)
        for (int j = 0; j < mycols.size(); j++)
            B[myrows[i]][mycols[j]] = (i + j) % 2;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> S[i];
    for (int i = 0; i < n; i++)
        cin >> T[i];
    for (int i = 0; i < n; i++)
        cin >> U[i];
    for (int i = 0; i < n; i++)
        cin >> V[i];
    for (int i = 0; i < Maxb; i++) {
        for (int j = 0; j < n; j++) {
            row[j] = bool(U[j] & ull(1) << ull(i));
            col[j] = bool(V[j] & ull(1) << ull(i));
        }
        if (!Solve()) { printf("-1\n"); return 0; }
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++)
                if (B[r][c]) res[r][c] |= ull(1) << ull(i);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << res[i][j] << (j + 1 < n? ' ': '\n');
    return 0;
}
