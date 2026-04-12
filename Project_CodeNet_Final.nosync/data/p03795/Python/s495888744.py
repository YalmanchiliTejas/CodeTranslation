def inint(): return int(input())
def inlint(): return list(map(int, input().split()))
def infloat(): return float(input())
def inlffloat(): return list(map(float, input().split()))
def inl(): return list(input())
def putlint(): return "".join(list(map(str, ans)))

n = inint()

a =int( n/15)
print(n*800-a*200)