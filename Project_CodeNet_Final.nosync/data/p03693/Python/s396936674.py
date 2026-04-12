# -*- coding: utf-8 -*-

nums = list(map(int, input().rstrip().split()))

if ( nums[0]*100 + nums[1]*10 + nums[2] ) % 4 == 0:
    print("YES")
else:
    print("NO")
