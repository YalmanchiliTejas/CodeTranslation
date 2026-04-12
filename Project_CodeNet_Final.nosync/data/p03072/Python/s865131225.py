N,H = [input() for i in range(2)]
N=int(N)
H=H.split(' ')
for i in range(N):
    H[i]=int(H[i])
cnt = 0

for i in range(N):
    if i == 0:
        cnt += 1
    else:
        flag =  True
        for j in range(i):
            if H[i] < H[j]:
                flag = False
        if flag == True:
            cnt += 1

print(cnt)
