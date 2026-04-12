A=[chr(97+i) for i in range(26)]
T={a:float("inf") for a in A}

N=int(input())
for _ in range(N):
    S=input()
    for a in A:
        T[a]=min(T[a],S.count(a))

X=""
for a in A:
    X+=a*T[a]
print(X)
