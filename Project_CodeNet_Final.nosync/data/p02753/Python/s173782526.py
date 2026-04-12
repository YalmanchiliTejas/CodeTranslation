def Main(S):
    return "Yes" if 'A' in S and 'B' in S else "No"
    
def main():
    S = str(input())
    print(Main(S))

if __name__ == '__main__':
    main()