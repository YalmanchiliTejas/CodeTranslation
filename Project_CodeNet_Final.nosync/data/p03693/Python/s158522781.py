#N = int(input())
#A = [int(x) for x in input().split()]
#a, b, c = map(int, input().split())
#name1 = str(input())
#alph = {"A": 1, "B": 2, "C": 3, "D": 4, "E": 5}
a, b ,c= map(int, input().split())
num = a*100+b*10+c
if num%4==0:
    print("YES")
else:
    print("NO")
