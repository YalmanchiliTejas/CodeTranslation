"""
AtCoder Beginner Contest 064
A - RGB Cards
@author Ren Serizawa
"""

import sys
nums = [num for num in input().split(" ")]
num3digit = int(("").join(nums)) if ("").join(nums).isdigit() else -1
if num3digit < 0 or not len(nums) == 3:
    sys.stderr.write("Error: Invalid input\n")
    exit()
isMultipleOf4 = "YES" if num3digit % 4 == 0 else "NO"
print(isMultipleOf4)
exit()