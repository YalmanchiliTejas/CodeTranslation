from sys import stdin
N = int(stdin.readline().rstrip())
Hs = [ int(_) for _ in stdin.readline().rstrip().split()]
ans = 1
highest= Hs[0]
for i in range(1,N):
    if highest <= Hs[i]:
        ans+=1
        if highest < Hs[i]:
            highest = Hs[i]
print(ans)