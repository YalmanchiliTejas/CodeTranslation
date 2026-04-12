def main():

    S = list(input())
    checklist = [0 for i in range(26)]
    for i in S:
        checklist[ord(i) - ord("a")] += 1
    ans = True

    for i in checklist:
        if i > 1:
            ans = False

    if not ans:
        print(-1)
        return 0
    else:
        ans = False
        for i in range(len(checklist)):
            if checklist[i] == 0:
                for i in S:
                    print(i, end="")
                print(chr(i + ord("a")), end = "")
                print()
                ans = True
                break

        if not ans:
            new_S = []
            for i in S:
                new_S.append(ord(i))

            for i in range(len(new_S) - 1):
                if new_S[i] > new_S[i + 1]:
                    for j in range(i - 1):
                        print(S[j], end = "")
                    print(chr(new_S[i - 1] + 1), end = "")
                    print()
                    ans = True
                    break

            if not ans:
                print(-1)
#main()

def ABC069D():

    H, W = map(int, input().split())
    N = int(input())
    a = list(map(int, input().split()))
    ans = []
    for i in range(N):
        for j in range(a[i]):
            ans.append(i + 1)
    printlist = [[0 for i in range(W)] for j in range(H)]
    k = 0
    for i in range(H):
        for j in range(W):
            printlist[i][j] = ans[k]
            k += 1
        if i % 2 != 0:
            printlist[i] = printlist[i][::-1]

    for i in range(H):
        for j in range(W):
            print(printlist[i][j], end = "")
            if j != W:
                print(" ", end = "")
        print()
    print()
#ABC069D()

import math
def cc(n, r):
    return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))

def ABC057D():

    N, A, B = map(int, input().split())
    v = list(map(int, input().split()))
    v = sorted(v)[::-1]

    anslist = []
    for i in range(A, B + 1):

        anslist.append([sum(v[0:i]) / i, i, v[i - 1]])
    anslist.sort()
    anslist = anslist[::-1]
    ans = anslist[0][0]
    key = anslist[0][2]
    long = anslist[0][1]
    print(ans)
    for i in range(1, len(anslist)):
        if anslist[i][0] == anslist[i - 1][0]:
            ans = anslist[i][0]
            key = anslist[i][2]
            long = anslist[i][1]
        else:
            break
    #print(anslist)
    #print(ans, key, long)
    cnt = 0
    for i in v:
        if i == key:
            cnt += 1

    c = 0
    for i in v[:long]:
        #print(i)
        if i == key:
            c += 1
    #print(c, long)
    ans = 0
    if c == long:
        for i in range(A,  min(B + 1, cnt + 1)):
            ans += cc(cnt, i)
    else:
        ans = cc(cnt, c)
    #print(anslist)
    #print(cnt, c, long)
    print(ans)
#ABC057D()

def ABC104D():
    S = list(input())
    A_cnt = 0
    B_cnt = 0
    C_cnt = 0
    Q_cnt = 0
    ans = 0
    for i in S:
        if i == "A":
            A_cnt += 1
        elif i == "B":
            B_cnt += 1
        elif i == "C":
            C_cnt += 1
        else:
            Q_cnt += 1
    for i in range(Q_cnt + 1):
        for j in range(Q_cnt - i + 1):
            k = Q_cnt - i - j
            if A_cnt + i > 0 and B_cnt + j > 0 and C_cnt + k > 0:
                f_i = math.factorial(i)
                f_j = math.factorial(j)
                f_k = math.factorial(k)
                if f_i == 0:
                    f_i = 1
                if f_j == 0:
                    f_j = 1
                if f_k == 0:
                    f_k = 1
                ans += (A_cnt + i) * (B_cnt + j) * (C_cnt + k) * math.factorial(Q_cnt) // f_i // f_j // f_k
                print(ans, i, j, k, A_cnt + i, B_cnt + j, C_cnt + k)
                print(math.factorial(Q_cnt), f_i, f_j, f_k)
    print(ans)
#ABC104D()

def ARC082D():
    N = int(input())
    p = list(map(int, input().split()))
    cnt = 0
    if p[N - 1] == N:
        #print(p[N - 1], N)
        p[-2], p[-1] = p[-1], p[-2]
        cnt += 1

    for i in range(N - 1):
        if p[i] == i + 1:
            p[i], p[i + 1] = p[i + 1], p[i]
            cnt += 1
    print(cnt)
#ARC082D()

from queue import Queue
def ABC070D():
    N = int(input())
    a, b, c =map(int, input().split())
    Q, K = map(int, input().split())
    xy = [list(map(int, input().split())) for i in range(Q)]
    x = [[] for i in range(N)]
    for i, j in xy:
        x[i - 1].append(j - 1)
        x[j - 1].append(i - 1)

    q = Queue()
    visited = [0 for i in range(N)]

def ABC076D():
    N = int(input())
    t = list(map(int, input().split()))
    v = list(map(int, input().split()))
    speed_lim = [0]
    speed_list = [0 for i in range(sum(t) + 1)]
    for i in range(N):
        for j in range(t[i]):
            speed_lim.append(v[i])
    print(speed_lim)
    for i in range(1, sum(t) + 1):
        speed_list[i] = speed_list[i - 1] + 1
        if speed_list[i] > speed_lim[i]:
            speed_list[i] = speed_lim[i]
    print(speed_list)
    speed_list[-1] = 0
    for i in range(sum(t) - 1, -1, -1):
        speed_list[i] = min(speed_list[i + 1] + 1, speed_list[i])
        if speed_list[i] > speed_lim[i + 1]:
            speed_list[i] = speed_lim[i + 1]
    print(speed_list)
    ans = 0
    for i in speed_list:
        ans += i

    print(ans)
#ABC076D()

def ABC085D():
    N, H = map(int, input().split())
    ab = [list(map(int, input().split())) for i in range(N)]
    a = []
    b = []
    for i, j in ab:
        a.append(i)
        b.append(j)
    a.sort()
    b.sort()
    a = a[::-1]
    b = b[::-1]
    damage = 0
    cnt = 0
    for i in b:
        if i < a[0]:
            break
        damage += i
        cnt += 1
        if damage >= H:
            break
    key = 0
    if damage < H:
        key = (H - damage) / a[0]
        if int(key) != key:
            key += 1
        key = int(key)

    cnt += key

    print(cnt)
#ABC085D()

def ARC068D():
    N = int(input())
    A = list(map(int, input().split()))
    A.sort()
    count_list = []
    cnt = 1
    #print(A)
    for i in range(1, N):
        if A[i] == A[i - 1]:
            cnt += 1
        else:
            count_list.append(cnt)
            cnt = 1
    count_list.append(cnt)
    ans_cnt = 0
    #print(count_list)
    for i in range(len(count_list)):
        if count_list[i] > 2:
            ans_cnt += (count_list[i] % 2) - 1
            count_list[i] %= 2
            if count_list[i] == 0:
                count_list[i] = 2
    #print(ans_cnt)
    count_list = sorted(count_list)[::-1]
    for i in range(len(count_list) - 1):
        if count_list[i] == 2 and count_list[i + 1] == 2:
            ans_cnt += 1
            count_list[i] = 1
            count_list[i + 1] = 1
    count_list = sorted(count_list)[::-1]
    if count_list[0] == 2:
        count_list[0] = 0
    #print(ans_cnt)
    #print(count_list)
    print(sum(count_list))
#ARC068D()

def ARC073D():
    N, W = map(int, input().split())
    wv = [list(map(int, input().split())) for i in range(N)]
    wv.sort()
    count_list = []
    cnt = 1
    weight_list = []
    s = 0
    g = 0
    for i in range(N - 1):
        if wv[i][0] != wv[i + 1][0]:
            g = i
            count_list.append(cnt)
            weight_list.append([wv[i][0], s, g, cnt])
            s = i + 1
            g = i + 1
            cnt = 1
        else:
            g = i
            cnt += 1

    count_list.append(cnt)
    weight_list.append([wv[-1][0], s, g, cnt])
    print(weight_list)
    wl = []
    for i in weight_list:
        this_weight = i[0]
        this_list = []
        for j in wv[i[1]:i[2] + 1]:
            this_list.append(j[1])
        this_list = sorted(this_list)[::-1]
        print(this_list)
        wl.append([this_weight, this_list])

def ARC081D():
    pattern = []
    N = int(input())
    S1 = list(input())
    S2 = list(input())
    i = 0
    while i < N:
        if S1[i] == S2[i]:
            pattern.append("X")
        else:
            pattern.append("Y")
            i += 1
        i += 1
    ans_list = []
    for i in range(len(pattern)):
        if i == 0:
            if pattern[i] == "X":
                ans_list.append(3)
            else:
                ans_list.append(6)
        else:
            if pattern[i] == "X":
                if pattern[i - 1] == "X":
                    ans_list.append(2)
                else:
                    ans_list.append(1)
            elif pattern[i] == "Y":
                if pattern[i - 1] == "X":
                    ans_list.append(2)
                elif pattern[i - 1] == "Y":
                    ans_list.append(3)
    #print(pattern)
    #print(ans_list)
    ans = 1
    for i in ans_list:
        ans *= i
    print(ans % (1000000007))
#ARC081D()

def ARC090D():
    N, M = map(int, input().split())
    LRD = [list(map(int, input().split())) for i in range(M)]
    L = []
    R = []
    D = []
    LRD.sort()
    root = [[] for i in range(N)]
    for i, j, k in LRD:
        L.append(i)
        R.append(j)
        D.append(k)
        root[i - 1].append(j - 1)
    print(root)
#ARC090D()

def ABC073D():
    N, M, R = map(int, input().split())
    r = list(map(int, input().split()))
    ABC = [list(map(int, input().split())) for i in range(M)]
    root = [[1000000000 for i in range(N)] for j in range(N)]
    for i, j, k in ABC:
        root[i - 1][j - 1] = k
        root[j - 1][i - 1] = k

    import itertools
    def kumiawase(list_name):  # list_name(リスト)のすべての並び替え
        return itertools.permutations(list_name)

    #for i in range(N):
     #   for j in range(N):
      #      for k in range(N):
       #         if root[i][j] > root[i][k] + root[k][j]:
        #            root[i][j] = root[i][k] + root[k][j]

    for i in range(N):
        for j in range(N):
            for k in range(N):
                if root[N - i - 1][N - j - 1] > root[N - i - 1][N - k - 1] + root[N - k - 1][N - j - 1]:
                    root[N - i - 1][N - j - 1] = root[N - i - 1][N - k - 1] + root[N - k- 1][N - j - 1]

    a = kumiawase(r)
    ans = float("inf")
    for i in a:
        key = 0
        for j in range(len(i) - 1):
            key += root[i[j] - 1][i[j + 1] - 1]
        if ans > key:
            ans = int(key)
    #print(root)
    print(ans)
#ABC073D()

def ARC061D():
    H, W, N = map(int, input().split())
    ab = [list(map(int, input().split())) for i in range(N)]
    ab.sort()
    tmp_list = []
    ans_list = [0 for i in range(10)]
    for x, y, in ab:
        for i in range(x - 3, x):
            for j in range(y - 3, y):
                if 0 <= i < H - 2 and 0 <= j < W - 2:
                    #print(x, y, i, j)
                    tmp_list.append([i, j])
    #print(tmp_list)
    tmp_list.sort()
    temp = 1
    #print(tmp_list)
    cnt = 0
    for i in range(1, len(tmp_list) + 1):
        if i != len(tmp_list):
            if tmp_list[i] == tmp_list[i - 1]:
                temp += 1
            else:
                ans_list[temp] += 1
                temp = 1
                cnt += 1
        else:
            ans_list[temp] += 1
            cnt += 1
    #print(ans_list)

    key = 0
    for i in range(len(ans_list)):
        key += i * ans_list[i]
    ans_list[0] = (H - 2) * (W - 2) - cnt
    #print(key)
    #print((H - 2) * (W - 2) - key)

    for i in range(10):
        print(ans_list[i])
#ARC061D()

from scipy.sparse import csgraph
#root = csgraph.floyd_warshall(root)

def ABC079D():
    H, W = map(int, input().split())
    c = [list(map(int, input().split())) for i in range(10)]
    A = [list(map(int, input().split())) for i in range(H)]
    #c = csgraph.floyd_warshall(c, False)
    for k in range(10):
        for i in range(10):
            for j in range(10):
                c[i][j] = min(c[i][j], c[i][k] + c[k][j])
    #print(c)
    ans = 0
    for i in A:
        for j in i:
            if j != -1 and j != 1:
                ans += c[j][1]
                #print(c[j][1], j)
    print(int(ans))
#ABC079D()

import fractions
def lcm(x, y):
    return (x * y) // fractions.gcd(x, y)

def AGC028A():
    N, M = map(int, input().split())
    S = input()
    T = input()

    key = lcm(N, M)
    n = key // N
    m = key // M
    n_list = []
    for i in range(0, key, n):
        n_list.append(i)
    m_list = []
    for j in range(0, key, m):
        m_list.append(j)

    #print(n_list, m_list)
    i = 0
    j = 0
    while True:
        if i >= len(n_list) or j >= len(m_list):
            break
        if i >= len(S) or j >= len(T):
            break
        if n_list[i] == m_list[j]:
            if S[i] != T[j]:
                print(-1)
                return 0
        if n_list[i] > m_list[j]:
            j += 1
        elif n_list[i] < m_list[j]:
            i += 1
        else:
            i += 1
            j += 1
    print(key)
#AGC028A()

import math
def AGC028B():
    N = int(input())

    A = list(map(int, input().split()))
    import copy
    a = copy.deepcopy(A)
    for i in range(1, N):
        A[i] += A[i - 1]
    ans = 0
    for i in range(1, N):
        key = A[i] * 2 - A[0] - (A[i] - A[i - 1])
        ans += math.factorial(N - i) * i * key
        #print(key)
    print(ans)
    A = copy.deepcopy(a[::-1])
    for i in range(1, N):
        A[i] += A[i - 1]
    print(A)
    for i in range(1, N):
        key = A[i] * 2 - A[0] - (A[i] - A[i - 1])
        ans += math.factorial(N - i) * i * key
        #print(key)
    ans += A[N - 1] * math.factorial(N - 1)

    print(ans)
#AGC028B()

def AGC028B2():
    N = int(input())

    A = list(map(int, input().split()))
    import copy
    a = copy.deepcopy(A)
    for i in range(1, N):
        A[i] += A[i - 1]
    ans = 0
    for i in range(1, N):
        A[i] = A[i] * (i + 1) - A[i - 1]
    for i in range(1, N):
        ans += math.factorial(N - i) * i * A[i - 1]

    print(ans)
    ans += A[N - 1] * N

    print(ans)
#AGC028B2()

def CF18QBA():
    N = int(input())
    print(100 - 100 // N)
#CF18QBA()

def CF18QBB():
    N, X = map(int, input().split())
    ab = [list(map(int, input().split())) for i in range(N)]
    key = ab[0][1]
    ans = 0
    for i, j in ab:
        if j > key:
            key = j
            key2 = i
        ans += i * j
    ans += key * X
    print(ans)
#CF18QBB()

def CF18QBC():
    N = int(input())
    ans_list = [[0 for i in range(N)] for j in range(N)]
    key1 = 1
    key2 = key1
    for i in range(N):
        #print(key2)
        for j in range(N):
            if key2 == j:
                ans_list[i][j] = 1
                key2 += 5
        if key1 == 1:
            key1 = 3
        elif key1 == 3:
            key1 = 0
        elif key1 == 0:
            key1 = 2
        elif key1 == 2:
            key1 = 4
        elif key1 == 4:
            key1 = 1
        key2 = key1
    cnt = 0
    for i in range(N):
        for j in range(N):
            OK = 0
            if i > 0:
                if ans_list[i - 1][j] == 1:
                    OK = 1
            if i < N - 1:
                if ans_list[i + 1][j] == 1:
                    OK = 1
            if j > 0:
                if ans_list[i][j - 1] == 1:
                    OK = 1
            if j < N - 1:
                if ans_list[i][j + 1] == 1:
                    OK = 1
            if OK == 0:
                #cnt += 1
                ans_list[i][j] = 1
                1

    for i in ans_list:
        for j in i:
            if j == 0:
                print(".", end = "")
            if j == 1:
                print("X", end = "")
                cnt += 1
        print()
#CF18QBC()

def CF18QBE():
    N = int(input())
    ans = 10000
    tmp_list = []
    key = 69720375229712477164533808935312303556800
    for i in range(1, N + 1):
        tmp_list.append([key // i, i])
    ans = tmp_list[0][0]
    cnt = 0
    ans_list = []
    ans_list.append(["+", 1])
    key = []
    while True:
        if ans < 1 / N:
            print(1)
            break
        if cnt >= 320:
            print(2)
            break
        #print(ans)
        #print(tmp_list)
        for i in range(len(tmp_list)):
            if tmp_list[i][0] < ans:
                key = tmp_list[i]
        if key:
            ans_list.append(["-", key[1]])
        if key:
            ans -= key[0]
        #print(ans)
        key = []
        cnt += 1
    #print(ans_list)
    print(len(ans_list))
    for i, j in ans_list:
        print(i, j)
#CF18QBE()

def niconicoB():
    N, C = map(int, input().split())
    L = [int(input()) for i in range(N)]
    L.sort()
    cnt = 0
    while len(L) > 0:
        if len(L) == 1:
            cnt += 1
            break
        if L[-1] + L[0] + 1 <= C:
            cnt += 1
            del L[0]
            del L[-1]
        else:
            cnt += 1
            del L[-1]
    print(cnt)
#niconicoB()

def ABC064D():
    N = int(input())
    S = list(input())
    cnt = 0
    start = 0
    for i in S:
        if i == "(":
            cnt += 1
        elif i == ")":
            cnt -= 1
        if cnt < 0:
            start += 1
            cnt += 1
    tmp = []
    for i in range(start):
        tmp.append("(")
    S = tmp + S
    cnt_start = 0
    cnt_end = 0
    for i in S:
        if i == "(":
            cnt_start += 1
        elif i == ")":
            cnt_end += 1
    tmp = []
    for i in range(cnt_start - cnt_end):
        tmp.append(")")
    S = S + tmp

    for i in S:
        print(i, end = "")
    print()
#ABC064D()

from operator import itemgetter

def ARC072C():
    N = int(input())
    a = list(map(int, input().split()))
    cnt1 = 0
    cnt2 = 0
    sum1 = a[0]
    sum2 = a[0]
    if sum1 <= 0:
        cnt1 = 1 - a[0]
        sum1 = 1
    if sum2 >= 0:
        cnt2 = abs(-1 - a[0])
        sum2 = -1
    j = 1
    #print(sum1, sum2)
    for i in range(1, N):
        sum1 += a[i]
        sum2 += a[i]
        if j % 2 == 0:
            if sum1 <= 0:
                cnt1 += 1 - sum1
                sum1 = 1
            if sum2 >= 0:
                cnt2 += abs(-1 - sum2)
                sum2 = -1
        else:
            if sum1 >= 0:
                cnt1 += abs(-1 - sum1)
                sum1 = -1
            if sum2 <= 0:
                cnt2 += 1 - sum2
                sum2 = 1
        j += 1
        #print(sum1, sum2)
    #print(cnt1, cnt2)
    print(min(cnt1, cnt2))
#ARC072C()

inf = 10 ** 15

def dijkstra(s, M, N):#s:start_node, M:node_list, N:graf_size
    color = [0 for i in range(N)] #0:white 1:gray 2:black
    d = [inf for i in range(N)]
    p = [-inf for i in range(N)]
    d[s] = 0
    p[s] = 0
    while True:
        mincost = inf
        for i in range(N):
            if color[i] != 2 and d[i] < mincost:
                mincost = d[i]
                u = i
        if mincost == inf:
            break

        color[u] = 2

        for v in range(N):
            if color[v] != 2 and M[u][v] != inf:
                if d[u] + M[u][v] < d[v]:
                    d[v] = d[u] + M[u][v]
                    p[v] = u
                    color[v] = 1
    return d

def ABC012D():
    N, M = map(int, input().split())
    abt = [list(map(int, input().split())) for i in range(M)]
    M = [[inf for i in range(N)] for i in range(N)]
    for i, j, k in abt:
        M[i - 1][j - 1] = k
        M[j - 1][i - 1] = k

    dist = []
    for i in range(N):
        dist.append(dijkstra(i, M, N))

    ans = 10000000000000000000
    for i in range(N):
        if ans > max(dist[i]):
            ans = max(dist[i])
    print(ans)
    #print(dist)
#ABC012D()

def ABC051D():
    N, M = map(int, input().split())
    DP = [[10000 for i in range(N)] for j in range(N)]
    check = [[1 for i in range(N)] for j in range(N)]
    pointlist = []
    for i in range(M):
        a, b, c = map(int, input().split())
        DP[a - 1][b - 1] = c
        DP[b - 1][a - 1] = c
        pointlist.append([a, b, c])

    for k in range(N):
        for i in range(N):
            for j in range(N):
                DP[i][j] = min([DP[i][j], DP[i][k] + DP[k][j]])

    cnt = 0
    for i in pointlist:
        if DP[i[0] - 1][i[1] - 1] != i[2]:
            cnt += 1

    print(cnt)
#ABC051D()

def ABC070D():
    N = int(input())
    abc = [list(map(int, input().split())) for i in range(N - 1)]
    ab = [[10000000000000 for i in range(N)] for j in range(N)]
    Q, K = map(int, input().split())
    xy = [list(map(int, input().split())) for i in range(Q)]
    for i, j, k in abc:
        ab[i - 1][j - 1] = k
        ab[j - 1][i - 1] = k

    for k in range(N):
        for i in range(N):
            for j in range(N):
                ab[i][j] = min(ab[i][j], ab[i][k] + ab[k][j])

    for x, y in xy:
        print(ab[x - 1][K - 1] + ab[K - 1][y - 1])
#ABC070D()

def ABC088D():

    H, W = map(int, input().split())
    s = [list(input()) for i in range(H)]
    visited = [[False for i in range(W)] for i in range(H)]
    black_cnt = 0
    for i in range(H):
        for j in range(W):
            if s[i][j] == "#":
                visited[i][j] = True
                black_cnt += 1
    will_visit = [[0, 0, 0]]
    def sarch(i, j, dist):
        visited[i][j] = True
        if 0 <= i - 1:
            if not visited[i - 1][j]:
                will_visit.append([i - 1, j, dist + 1])
        if 0 <= j - 1:
            if not visited[i][j - 1]:
                will_visit.append([i, j - 1, dist + 1])
        if j + 1 < W:
            if not visited[i][j + 1]:
                will_visit.append([i, j + 1, dist + 1])
        if i + 1 < H:
            if not visited[i + 1][j]:
                will_visit.append([i + 1, j, dist + 1])

    key = 0
    next = 0
    while len(will_visit) > next:
        #print(will_visit)
        next_i = will_visit[next][0]
        next_j = will_visit[next][1]
        next_dist = will_visit[next][2]
        if not visited[next_i][next_j]:
            if next_i == H - 1 and next_j == W - 1:
                key = next_dist
                break
            sarch(next_i, next_j, next_dist)
        if key != 0:
            break
        next += 1
    if key == 0:
        print(-1)
    else:
        key += 1
        print(H * W - key - black_cnt)
#ABC088D()

def ABC089D():
    H, W, D = map(int, input().split())
    A = [list(map(int, input().split())) for i in range(H)]
    Q = int(input())
    LR = [list(map(int, input().split())) for i in range(Q)]
    number_place = [[] for i in range(H * W)]
    for i in range(H):
        for j in range(W):
            number_place[A[i][j] - 1] = [i, j]
    d = [0 for i in range(H * W)]
    for i in range(D):
        d[i] = 0
    for i in range(D, H * W):
        past_y = number_place[i - D][0]
        past_x = number_place[i - D][1]
        now_y = number_place[i][0]
        now_x = number_place[i][1]
        d[i] = abs(now_x - past_x) + abs(now_y - past_y) + d[i - D]
    for i, j in LR:
        print(d[j - 1] - d[i - 1])
#ABC089D()

def ARC059D():
    s = input()

    for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
            print(i + 1, i + 2)
            return 0

    for i in range(len(s) - 2):
        if s[i] == s[i + 2]:
            print(i + 1, i + 3)
            return 0

    print(-1, -1)
#ARC059D()

def Q18A():
    N = int(input())
    print(2014 + (N - 1) * 4)
#Q18A()

def Q18B():

    Q = int(input())
    ABC = [list(map(int, input().split())) for i in range(Q)]
    for i, j, k in ABC:
        key = 100 * i + 10 * j + 1 * k
        if key % 2 != 0:
            print("No")
        else:
            now = key // 2
            a = min(now // 100, i)
            now -= 100 * a
            b = min(now // 10, j)
            now -= 10 * b
            c = min(now, k)
            now -= c
            if now == 0:
                print("Yes")
            else:
                print("No")
#Q18B()

def T112aA():
    n = int(input())
    ans = 0
    dp = [[0, 0] for i in range(n + 1)]
    dp[0][0] = 1
    for i in range(1, n + 1):
        dp[i][0] = dp[i - 1][1]
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1]
    #print(dp)
    print(sum(dp[n]))
#T112aA()

def ABC099C():
    N = int(input())
    res = N
    for i in range(N + 1):
        cnt = 0
        t = i
        while t > 0:
            cnt += t % 6
            t //= 6
        t = N - i
        while t > 0:
            cnt += t % 9
            t //= 9
        if res > cnt:
            res = cnt
    print(res)
#ABC099C()

def ctf14A():
    A, B = map(int, input().split())
    print(4 * A + 2 * B)
#ctf14A()

def gijutushitu3A():
    a, c1 = input().split()
    b, c2 = input().split()
    c1 = int(c1)
    c2 = int(c2)
    if a == "W":
        c1 *= -1
    if b == "W":
        c2 *= -1
    print(abs(c1 - c2) // 15)
#gijutushitu3A()

def t118A():
    S = input()
    if len(S) == 2:
        print(S)
    else:
        print(S[::-1])
#t118A()

def t118B():
    A, B, K = map(int, input().split())
    while True:
        if K <= 0:
            break
        if A % 2 != 0:
            A -= 1
        A //= 2
        B += A
        K -= 1
        #print(A, B)
        if K <= 0:
            break
        if B % 2 != 0:
            B -= 1
        B //= 2
        A +=  B
        K -= 1
        #print(A, B)
    print(A, B)
#t118B()

def t118C():
    N = int(input())
    A = [int(input()) for i in range(N)]
    A.sort()
    AFromMinimum = A
    AFromMaxim = A[::-1]
    ans = 0
    if N % 2 == 0:
        ans = -2 * sum(AFromMinimum[:N // 2]) + 2 * sum(AFromMaxim[:N // 2]) + AFromMinimum[N // 2 - 1] - AFromMaxim[N // 2 - 1]
    else:
        c = (N - 1) // 2
        tmp1 = -2 * sum(A[:c]) + 2 * sum(A[c + 2:]) + A[c] + A[c + 1]
        tmp2 = -2 * sum(A[:c - 1]) + 2 * sum(A[c + 1:]) - A[c - 1] - A[c]
        ans = max(tmp1, tmp2)
    print(ans)
t118C()

def KU18A():
    N = int(input())
    s = list(map(int, input().split()))
    a = list(map(int, input().split()))
    sa = [s[i] * a[i] for i in range(N)]
    print(max(sa))
#U18A()