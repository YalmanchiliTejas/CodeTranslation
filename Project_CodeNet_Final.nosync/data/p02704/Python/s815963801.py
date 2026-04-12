N = int(input())
S = list(map(int,input().split()))
T = list(map(int,input().split()))
U = list(map(int,input().split()))
V = list(map(int,input().split()))

def invalid_exit():
    print(-1)
    exit()

ans = [[0]*N for _ in range(N)]
for k in range(64):
    tmp = [[-1]*N for _ in range(N)]
    row_has_0 = [0] * N
    col_has_0 = [0] * N
    row_has_1 = [0] * N
    col_has_1 = [0] * N
    def fill(i,j,bit):
        if bit == 1 - tmp[i][j]: invalid_exit()
        tmp[i][j] = bit
        if bit:
            row_has_1[i] = col_has_1[j] = 1
        else:
            row_has_0[i] = col_has_0[j] = 1
    blank_rows = set(range(N))
    blank_cols = set(range(N))
    for i,(s,u) in enumerate(zip(S,U)):
        x = (u>>k)&1
        if s==0 and x:
            for j in range(N):
                tmp[i][j] = 1
                col_has_1[j] = 1
            row_has_1[i] = 1
            blank_rows.remove(i)
        elif s and x==0:
            for j in range(N):
                tmp[i][j] = 0
                col_has_0[j] = 1
            row_has_0[i] = 1
            blank_rows.remove(i)
    for j,(t,v) in enumerate(zip(T,V)):
        x = (v>>k)&1
        if t==0 and x:
            for i in range(N):
                if tmp[i][j] == 0: invalid_exit()
                tmp[i][j] = 1
                row_has_1[i] = 1
            col_has_1[j] = 1
            blank_cols.remove(j)
        elif t and x==0:
            for i in range(N):
                if tmp[i][j] == 1: invalid_exit()
                tmp[i][j] = 0
                row_has_0[i] = 1
            col_has_0[j] = 1
            blank_cols.remove(j)

    for _ in range(2):
        if blank_rows or blank_cols:
            j = list(blank_cols)[0] if len(blank_cols)==1 else None
            for i,(s,u) in enumerate(zip(S,U)):
                x = (u>>k)&1
                if s==0 and x==0:
                    if not row_has_0[i] and len(blank_cols) == 0: invalid_exit()
                    if j is not None:
                        y = (V[j]>>k)&1
                        if x==y:
                            fill(i,j,x)
                        else:
                            if x==0 and (not row_has_0[i]) and (not col_has_1[j]) and len(blank_rows) < 2: invalid_exit()
                            if x==1 and (not row_has_1[i]) and (not col_has_0[j]) and len(blank_rows) < 2: invalid_exit()
                            if row_has_0[i]:
                                fill(i,j,1)
                            else:
                                fill(i,j,0)
                        blank_rows.remove(i)
                elif s and x:
                    if not row_has_1[i] and len(blank_cols) == 0: invalid_exit()
                    if j is not None:
                        y = (V[j]>>k)&1
                        if x==y:
                            fill(i,j,x)
                        else:
                            if x==0 and (not row_has_0[i]) and (not col_has_1[j]) and len(blank_rows) < 2: invalid_exit()
                            if x==1 and (not row_has_1[i]) and (not col_has_0[j]) and len(blank_rows) < 2: invalid_exit()
                            if row_has_0[i]:
                                fill(i,j,1)
                            else:
                                fill(i,j,0)
                        blank_rows.remove(i)
            if j is not None:
                blank_cols = set()

        if blank_rows or blank_cols:
            i = list(blank_rows)[0] if len(blank_rows)==1 else None
            for j,(t,v) in enumerate(zip(T,V)):
                x = (v>>k)&1
                if t==0 and x==0:
                    if not col_has_0[j] and len(blank_rows) == 0: invalid_exit()
                    if i is not None:
                        y = (U[i]>>k)&1
                        if x==y:
                            fill(i,j,x)
                        else:
                            if x==0 and (not col_has_0[i]) and (not row_has_1[j]) and len(blank_cols) < 2: invalid_exit()
                            if x==1 and (not col_has_1[i]) and (not row_has_0[j]) and len(blank_cols) < 2: invalid_exit()
                            if col_has_0[i]:
                                fill(i,j,1)
                            else:
                                fill(i,j,0)
                        blank_cols.remove(j)
                elif t and x:
                    if not col_has_1[j] and len(blank_rows) == 0: invalid_exit()
                    if i is not None:
                        y = (U[i]>>k)&1
                        if x==y:
                            fill(i,j,x)
                        else:
                            if x==0 and (not col_has_0[i]) and (not row_has_1[j]) and len(blank_cols) < 2: invalid_exit()
                            if x==1 and (not col_has_1[i]) and (not row_has_0[j]) and len(blank_cols) < 2: invalid_exit()
                            if col_has_0[i]:
                                fill(i,j,1)
                            else:
                                fill(i,j,0)
                        blank_cols.remove(j)
            if i is not None:
                blank_rows = set()

    assert len(blank_rows) != 1
    assert len(blank_cols) != 1
    for i,r in enumerate(blank_rows):
        for j,c in enumerate(blank_cols):
            tmp[r][c] = (i%2)^(j%2)
    for i,row in enumerate(tmp):
        for j,c in enumerate(row):
            if c == -1: invalid_exit()
            if c:
                ans[i][j] |= (1<<k)

for row in ans:
    print(*row)