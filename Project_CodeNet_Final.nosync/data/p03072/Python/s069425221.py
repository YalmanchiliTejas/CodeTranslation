N = int(input())
H = list(map(int, input().split()))
cnt = 0
max = H[0]
for i in H:
    if(i>=max):
        cnt+=1
        max=i
print(cnt)

