# -*- coding: utf-8 -*-

import sys
import subprocess
import json
import time
import math
import re
import sqlite3

r, g, b = map(int, input().split())
if (g*10 + b) % 4 == 0: print("YES")
else: print("NO")
        
