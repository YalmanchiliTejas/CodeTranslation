# -*- coding: utf-8 -*-
def main():
    S = list(str(input()))
    if len(set(S))>1:
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()