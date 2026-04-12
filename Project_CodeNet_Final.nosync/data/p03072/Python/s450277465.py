from functools import reduce
n = int(input())
ary1 = list(map(int,input().split()))
print(len(reduce(lambda a, b: a+[b] if a[-1]<= b else a, ary1[1:],[ary1[0]])))
