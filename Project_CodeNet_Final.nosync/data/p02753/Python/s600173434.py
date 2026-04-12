S=list(raw_input())

#print S

if S[0] == 'A':
    if S[1] == 'B' or S[2] == 'B':
        print 'Yes'
    else:
        print 'No'
else:
    if S[1] == 'A' or S[2] == 'A':
        print 'Yes'
    else:
        print 'No'
