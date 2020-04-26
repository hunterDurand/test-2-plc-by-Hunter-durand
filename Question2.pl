$x = 1;
sub subfunc1 {
return $x;
}
sub staticscoping {
my $x = 2;
return subfunc1();
}
$y = 3;
sub subfunc2 {
return $y;
}
sub dynamicscoping {
local $y = 4;
return subfunc2();
}
print "static scope ", staticscoping(), "\n";
print "dynamic scope ", dynamicscoping(), "\n";
