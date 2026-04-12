N = int(input())
L = list(map(int,input().split()))

ans = 1

for i in range(1,N) :
    if max(L[:i]) <= L[i] :
        ans += 1
        #print(i,"q")
print(ans)


