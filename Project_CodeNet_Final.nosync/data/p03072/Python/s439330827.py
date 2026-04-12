#ABC124 B
N = int(input())
H = list(map(int, input().split()))
ans = 1
for i in range(N):
    if i==0:
        pass
    else:        
        i_bool = True
        for j in range(1,i+1):
            if H[j-1] > H[i]:
                i_bool = False
        if i_bool:
            ans+=1
print(ans)                    