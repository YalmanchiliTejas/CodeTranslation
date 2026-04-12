ans_list = []

while True:
    n,l,r = map(int,input().split())
    if (n,l,r) == (0,0,0):
        break
    A = [int(input()) for _ in range(n)]
    cnt = 0
    for x in range(l,r+1):
        for i,a in enumerate(A,1):
            if x % a == 0:
                if i % 2 == 1:
                    cnt += 1
                break
            if i == n:
                if n % 2 == 0:
                    cnt += 1
    ans_list.append(cnt)

for ans in ans_list:
    print(ans)
