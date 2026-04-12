N = int(input())
S = []

for _ in range(N):
    S.append(input())

    
ans = sorted(list(set(S[0]))) #unique

for a in ans:
    num = 9999999999
    for s in S:
        if num > s.count(a):
            num = s.count(a)
    print(a * num, end="");