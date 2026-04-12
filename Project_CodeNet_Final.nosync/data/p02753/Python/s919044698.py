import sys
S = input()

if not ( len(S) == 3 and ( "A" in S or "B" in S)): sys.exit()

print('No') if S == 'AAA' or S == 'BBB' else print('Yes')