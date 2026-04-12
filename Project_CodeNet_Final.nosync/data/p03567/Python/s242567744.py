import re
s = input().rstrip()
print('Yes' if re.search('AC', s) else 'No')
