N=int(input())
X=[int(i) for i in input().split()]
s=sorted(X)

l=s[N//2-1]
r=s[N//2]

for i in range(N):
    if X[i]<=l:
        print(r)
    else:
        print(l)
