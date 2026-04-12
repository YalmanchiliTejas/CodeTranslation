n = int(input())
s = input()
k = int(input())
k -= 1

import re
print(re.sub('[^' + s[k] + ']', '*', s))
