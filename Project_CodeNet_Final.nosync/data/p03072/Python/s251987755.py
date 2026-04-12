N = int(input())
H = list(map(int,input().split()))
saidai = 0
cnt = 0

for i in H:
    if(i >= saidai):
        saidai = i
        cnt += 1
    

print(cnt)