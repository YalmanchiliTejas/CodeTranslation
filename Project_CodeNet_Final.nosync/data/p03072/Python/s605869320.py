N = int(input())
li_n = list(map(int,input().split()))
count = 1
max = li_n[0]
for i in range(1,N):
    if li_n[i] >= max:
        count += 1
        max = li_n[i]
print(count)