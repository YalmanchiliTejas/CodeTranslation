# AGC057 A Shik and Stone
from collections import Counter

h,w = map(int, input().split())

_list = []
for i in range(h):
    _list += list(input())

if _list.count("#") == (h+w-1):
    print("Possible")
else:
    print("Impossible")