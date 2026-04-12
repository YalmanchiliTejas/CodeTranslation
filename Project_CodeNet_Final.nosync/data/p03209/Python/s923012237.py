import sys
input=sys.stdin.readline

N,X = map(int,input().split())

a = [1]
p = [1]
for i in range(N):
    a.append(a[i]*2 + 3)
    p.append(p[i]*2 + 1)

# レベル lv のバーガーの下から x 枚に含まれるパティの数
def f(lv, x):
    if lv == 0:
        return 0 if x <= 0 else 1
    elif x <= 1 + a[lv-1]:
        return f(lv-1, x-1)
    else:
        return p[lv-1] + 1 + f(lv-1, x -1 -a[lv-1] -1)

def main():
    print(f(N,X))

if __name__ == '__main__':
    main()
