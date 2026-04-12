N = int(input())
H = list(map(int,input().split()))
maxhigh = H[0]
answer = 0

for x in H:
    if maxhigh <= x:
        answer += 1
        maxhigh = x

print(answer)