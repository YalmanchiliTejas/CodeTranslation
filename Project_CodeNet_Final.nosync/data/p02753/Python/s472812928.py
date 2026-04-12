def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))

S = input()

if S == "AAA" or S == "BBB":
    print("No")
else:
    print("Yes")
