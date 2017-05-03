#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(255);
	ofEnableDepthTest();
	ofSetFrameRate(60);
	ofSetWindowTitle("NoiseBox");

	this->x_noise = ofRandom(10.0);
	this->y_noise = ofRandom(10.0);

	for (int x = 0; x < this->x_len; x++) {
		for (int y = 0; y < this->x_len; y++) {
			locations[x][y] = ofVec3f(x * this->box_size - ofGetWidth() / 2, y * this->box_size - ofGetHeight() / 2, 0);
		}
	}
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	float tmp_x_noise = x_noise;
	float tmp_y_noise = y_noise;
	float noise_value = 0.025;

	for (int x = 0; x < this->x_len; x++) {

		tmp_x_noise += noise_value;
		tmp_y_noise = y_noise;
		for (int y = 0; y < this->y_len; y++) {

			tmp_y_noise += noise_value;
			ofVec3f location = this->locations[x][y];

			ofPushMatrix();
			ofTranslate(location);
			ofBoxPrimitive box;

			float noise_value = ofNoise(tmp_x_noise, tmp_y_noise);
			ofColor c;
			c.setHsb(ofNoise(tmp_x_noise, tmp_y_noise) * 255, 255, 255);
			ofSetColor(c);

			box.set(this->box_size * 0.8, this->box_size * 0.8, this->box_size * noise_value * 20);
			//ofTranslate(0, 0, this->box_size * noise_value * 10);

			box.draw();
			ofPopMatrix();
		}
	}

	this->x_noise += noise_value;
	this->y_noise += noise_value;

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}