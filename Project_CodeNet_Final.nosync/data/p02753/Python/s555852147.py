import sys
range = xrange
input = raw_input

S = input()
if all(c == 'B' for c in S) or all(c == 'A' for c in S):
    print 'No'
else:
    print 'Yes'
