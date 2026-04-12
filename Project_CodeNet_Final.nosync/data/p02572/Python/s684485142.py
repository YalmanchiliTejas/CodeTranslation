N=int(input())
List = list(map(int, input().split()))
S=0
for i in range(len(List)):
    S+=List[i]
mod=10**9+7
S=S%mod
T=0
s=0
for i in range(len(List)):
    s+=List[i]
    s=s%mod
    T+=List[i]*(S-s)
    T=T%mod
print(T)