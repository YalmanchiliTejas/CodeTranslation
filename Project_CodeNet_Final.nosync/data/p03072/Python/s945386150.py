n = input()
h = list(map(int, input().split()))
li =[]
cnt = 0
for i in h:
    li.append(i)
    if li[-1] == max(li):
        cnt += 1
print (str(cnt))
