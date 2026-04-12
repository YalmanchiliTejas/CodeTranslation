import re

s = input()
if re.match(".*AC.*", s):
    print("Yes")
else:
    print("No")
