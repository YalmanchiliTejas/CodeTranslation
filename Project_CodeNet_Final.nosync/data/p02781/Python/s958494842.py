import itertools
N = input()
K = int(input())
l = len(N)
S = list(map(int, N))
N = int(N)

if K == 1:
    ans = S[0] + 9*(l-1)
elif K == 2 and l >= 2:
    # 最大桁がN未満のとき
    ans = (S[0]-1)*9*(l-1)
    # 最大桁がNのとき
    for i in range(1, l):
        if S[0]*10**(l-1)+9*10**(l-i-1) <= N:
            ans += 9
        else:
            ans += S[i]
    # 最大桁が0のとき
    if l > K:
        ans += (l-1)*(l-2)//2*9**2
elif K == 3 and l >= 3:
    # 最大桁がN未満のとき
    ans = (S[0]-1)*(l-1)*(l-2)//2*9**2
    # 最大桁がNのとき
    for a, b in itertools.combinations(range(1, l), 2):
        if S[0]*10**(l-1)+9*10**(l-a-1) <= N:
            if S[0]*10**(l-1)+9*10**(l-a-1)+9*10**(l-b-1) <= N:
                ans += 9**2
            else:
                ans += 8*9 + S[b]
        else:
            if S[0]*10**(l-1)+S[a]*10**(l-a-1)+9*10**(l-b-1) <= N:
                ans += S[a]*9
            else:
                if S[a] == 0:
                    pass
                else:
                    ans += (S[a]-1)*9 + S[b]
    # 最大桁が0のとき
    ans += (l-1)*(l-2)*(l-3)//6*9**3
else:
    ans = 0
print(ans)
