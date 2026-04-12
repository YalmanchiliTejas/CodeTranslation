n,x = map(int, input().split())

maisu=[0]*50
pate=[0]*50
maisu[0]=1
pate[0]=1

for i in range(1,50):
    maisu[i]=3+maisu[i-1]*2
    pate[i]=1+pate[i-1]*2

def solve(l,x):
    if l==0:
        return 1
    if x<=1:
        return 0

    if x<=1+maisu[l-1]:
        return solve(l-1,x-1)
    if x==2+maisu[l-1]:
        return pate[l-1] + 1

    return pate[l-1] + 1 + solve(l-1,x-2-maisu[l-1])

print(solve(n,x))