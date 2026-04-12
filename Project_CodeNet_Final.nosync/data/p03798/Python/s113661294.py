N = int(input())
S = input()

Ans = [[0] * N for _ in range(4)]
Ans[0][0] = 1
Ans[0][1] = 1
Ans[1][0] = 1
Ans[1][1] = 2
Ans[2][0] = 2
Ans[2][1] = 1
Ans[3][0] = 2
Ans[3][1] = 2

def isok(a):
    for i, s in enumerate(S):
        if i + 2 < N:
            if s == 'o':
                if a[i + 1] == 1:
                    a[i + 2] = a[i]
                else:
                    a[i + 2] = 3 - a[i]
            else:
                if a[i + 1] == 1:
                    a[i + 2] = 3 - a[i]
                else:
                    a[i + 2] = a[i]
        else:
            if s == 'o':
                if a[(i + 1) % N] == 1:
                    if a[(i + 2) % N] != a[i]:
                        return False
                else:
                    if a[(i + 2) % N] + a[i] != 3:
                        return False
            else:
                if a[(i + 1) % N] == 1:
                    if a[(i + 2) % N] + a[i] != 3:
                        return False
                else:
                    if a[(i + 2) % N] != a[i]:
                        return False
    return True

flag = True
num = -1
for i in range(4):
    if isok(Ans[i]):
        num = i
        flag = False
        break
if flag:
    print(-1)
else:
    for a in Ans[num][1:]:
        if a == 1:
            print('S', end='')
        else:
            print('W',end='')
    if Ans[num][0] == 1:
        print('S')
    else:
        print('W')