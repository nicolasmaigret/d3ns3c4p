#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // to crop an image and put it into another image
    img.load("/Users/gene/Teaching/ML4A/ml4a.github.io/_site/images/tsne_caltech256_animals.jpg");

    
    img_small1.setFromPixels(img.getPixels());
    img_small1.crop(50, 50, 100, 150);

    img_small2.setFromPixels(img.getPixels());
    img_small2.crop(250, 350, 200, 100);
    
    
    // to read json
    string file = "/Users/gene/Learn/densecap/vis/data/results.json";
    ofxJSONElement result;
    bool parsingSuccessful = result.open(file); // bool means it's successfull


    string img_name = result["results"][0]["img_name"].asString();
    int numScores = result["results"][0]["scores"].size();
    for (int k=0; k<numScores; k++) {
        float score = result["results"][0]["scores"][k].asFloat();
        string caption = result["results"][0]["captions"][k].asString();
        ofRectangle box(result["results"][0]["boxes"][k][0].asFloat(),
                        result["results"][0]["boxes"][k][1].asFloat(),
                        result["results"][0]["boxes"][k][2].asFloat(),
                        result["results"][0]["boxes"][k][3].asFloat());
        
        cout << "result "<< img_name<< " : "<<score<<" " << caption << " " << ofToString(box) << endl;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    img_small1.draw(100, 50);
    img_small2.draw(360, 250);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
