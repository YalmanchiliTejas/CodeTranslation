num = raw_input().strip().split(" ")
num = map(lambda x : int(x), num)

chair = num[0] - num[2]
cnt = 0
while True:
    if (chair - (num[1]+ num[2])) >=0:
        cnt += 1
        chair -= (num[1]+num[2])
    else:
        break
print(str(cnt))