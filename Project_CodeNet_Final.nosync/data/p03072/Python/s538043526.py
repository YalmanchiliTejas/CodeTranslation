N=int(input())
H=list(map(int, input().split())) 
count=0
for i in range(N):
    if H[i] >= H[0]:
        count+=1
        if H[i] > H[0]:
            H[0] = H[i]
    else:
        pass
print(count)
        