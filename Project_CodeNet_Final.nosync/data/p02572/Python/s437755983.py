def square(list):
    return [i ** 2 for i in list]
m = 1000000007
n = int(input())
A = list(map(int, input().split()))
sq = square(A)
s1 = sum(A)
s2 = sum(sq)
 
result = (s1**2-s2)//2
print(result%m)