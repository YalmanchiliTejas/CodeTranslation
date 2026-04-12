N=int(input())
s=list(input())
K=int(input())
t=s[K-1]
for i in range(N):
    if s[i]!=t:
        s[i]="*"
print("".join(s))
