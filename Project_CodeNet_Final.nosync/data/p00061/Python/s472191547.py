p = []
while True:
    s = input()
    if s == "0,0":
        break
    p.append([int(i) for i in s.split(",")])

p.sort(key = lambda x : x[1], reverse = True)

while True:
    try:
        n = int(input())
    except:
        break
    ans = 1
    for i in range(len(p)):
        if i != 0 and p[i][1] != p[i - 1][1]:
            ans += 1
        if p[i][0] == n:
            print(ans)
            break