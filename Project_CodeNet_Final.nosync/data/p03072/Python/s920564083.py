n = int(input())
h = list(map(int,input().split()))
li2 = [h[0]]
answer = 1
for i in range(1,n):
    if h[i] >= max(li2):
        answer+=1
    li2.append(h[i])
print(answer)
