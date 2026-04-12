# https://qiita.com/_-_-_-_-_/items/34f933adc7be875e61d0
# abcde	s=input()	s='abcde'
# abcde	s=list(input())	s=['a', 'b', 'c', 'd', 'e']
# 5(1つだけ)	a=int(input())	a=5
# 1 2	| x,y = map(int,input().split())|	x=1,y=2
# 1 2 3 4 5 ... n 　	li = input().split()	li=['1','2','3',...,'n']
# 1 2 3 4 5 ... n 　	li = list(map(int,input().split()))	li=[1,2,3,4,5,...,n]
# FFFTFTTFF 　	li = input().split('T')	li=['FFF', 'F', '', 'FF']

# INPUT
# 3
# hoge
# foo
# bar
# ANSWER
# n=int(input())
# string_list=[input() for i in range(n)]

import collections
def inpl(): return list(map(int, input().split()))

#### START
n = int(input())
S = [input() for i in range(n)]

c = collections.Counter(S[0])

for s in S[1:]:
  for cs in c.keys():
    c[cs] = min(s.count(cs), c[cs])

ans = [ k*v for k, v in c.items() if len(k*v) != 0]
print(*sorted(ans), sep="")