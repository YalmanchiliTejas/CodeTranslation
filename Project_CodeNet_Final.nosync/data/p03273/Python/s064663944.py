from numpy import*
h,w=int8(input().split())
a=array(eval('list(input()),'*h))
print(*map(''.join,a[any(a<'.',1)][:,any(a<'.',0)]))