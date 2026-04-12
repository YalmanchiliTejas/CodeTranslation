N = int(input())
H = list(map(int, input().split()))

def ok(H, i):
    for j in range(0,i):
        #print(i, j, H[i], H[j])
        if H[i] < H[j]:
            #print("out")
            return 0
    return 1

    
cnt = 1
for i in range(1, N):
    cnt += ok(H, i)

print(cnt)