#!/usr/bin/env python

import sys
import argparse
import logging

logging.basicConfig(filename='logger.log', level=logging.DEBUG)
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)


def f(x: int) -> str:
    '''
    >>> f(-40)
    'No'
    >>> f(-1)
    'No'
    >>> f(0)
    'No'
    >>> f(29)
    'No'
    >>> f(30)
    'Yes'
    >>> f(31)
    'Yes'
    >>> f(40)
    'Yes'
    '''
    if x >= 30:
        return "Yes"
    else:
        return "No"


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument(
            '--doctest', action='store_true', default=False)
    args = parser.parse_args()
    if args.doctest:
        import doctest
        doctest.testmod(verbose=True)
        sys.exit()

    x = int(sys.stdin.readline().rstrip())
    print(f(x))