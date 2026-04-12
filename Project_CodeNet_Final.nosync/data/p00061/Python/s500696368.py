arr = {}
rankScore = []
while True:
    s = list(map(int, input().split(',')))
    if s[0] == 0:
        break
    arr[s[0]] = s[1]
    if s[1] not in rankScore:
        rankScore.append(s[1])
rankScore.sort(reverse = True)
while True:
    try:
        num = int(input())
        print(rankScore.index(arr[num])+1)
    except:
        break