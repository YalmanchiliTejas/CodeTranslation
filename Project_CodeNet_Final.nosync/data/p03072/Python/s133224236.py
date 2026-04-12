N = int(input())
H_list = list(map(int,input().split()))

cnt =0
highest = 0

for i in range(N):
    if H_list[i] >= highest:
        cnt +=1
        highest = H_list[i]

print(cnt)
