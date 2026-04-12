N = int(input())
s = input()


def check_truth(a_0, a_1):
    a = [True for i in range(N)]  # True: Sheep, False: Wolf
    a[0] = a_0
    a[-1] = a_1
    for i in range(N):
        if a[i]:
            if s[i] == 'o':
                a[(i+1)%N] = a[i-1]
            else:
                a[(i+1)%N] = not a[i-1]
        else:
            if s[i] == 'o':
                a[(i+1)%N] = not a[i-1]
            else:
                a[(i+1)%N] = a[i-1]
    if a[0] != a_0 or a[-1] != a_1:
        return -1
    else:
        return a


p = [True, False]
for i in range(2):
    for j in range(2):
        ans = check_truth(p[i], p[j])
        if ans != -1:
            for k in range(N):
                if ans[k]:
                    print('S', end='')
                else:
                    print('W', end='')
            print()
            exit()
print(-1)