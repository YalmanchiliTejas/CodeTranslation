N = input()
H =  list(map(int, input().split()))

cnt = 0
now = 0

for i in range(len(H)):
    if now <= H[i]:
        now = H[i]
        cnt += 1

print(cnt)
