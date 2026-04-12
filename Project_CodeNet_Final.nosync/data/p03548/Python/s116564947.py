#https://atcoder.jp/contests/abc078/tasks/abc078_b
x, y, z = map(int, input().split())
for i in range(10**5):
    if y*i+z*(i+1) > x:
        print(i-1)
        break