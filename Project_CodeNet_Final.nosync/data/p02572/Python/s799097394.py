N = int(input())
List = list(map(int,input().split()))
LL = [item**2 for item in List]
mod = 10**9 + 7
ListTotal = sum(List)
ans = (ListTotal**2 - sum(LL))//2%mod
print(ans)