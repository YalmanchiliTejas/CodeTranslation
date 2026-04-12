N = int(input())
H = list(map(int,input().split()))
sea = [True]*N
for i in range(N):
    if i >=1:
        if all([H[i] >= H[j] for j in range(i) ] ):
            sea[i] = True

        else:
            sea[i] = False
ans = sum(sea)
print(ans)