S = raw_input()

def check():
    for i in range(len(S) - 1):
        if S[i:i+2] == 'AC':
            return True
    return False

print 'Yes' if check() else 'No'
