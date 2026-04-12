# coding: utf-8
# import re

S = input()
# print(S)

# if len(re.findall(("AB"or"BA"), S))>0:
#     print('Yes')
# else:
#     print('No')

if "AB" in S or "BA" in S:
    print('Yes')
else:
    print('No')
